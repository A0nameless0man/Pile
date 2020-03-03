param(
    $Dir = "./",
    $OutFile = $("sha1sumAt$(Get-Date -Format "yyyy-mm-dd--HH-mm").txt"),
    $fill = "*",
    $empty = " ",
    $updateSpeed = 1000
)
Write-Output "Will Write to $OutFile";

try {
    $throttleLimit = 4
    $SessionState = [system.management.automation.runspaces.initialsessionstate]::CreateDefault()
    $Pool = [runspacefactory]::CreateRunspacePool(1, $throttleLimit, $SessionState, $Host)
    $Pool.Open()
    $threads = @();
    $ansers = @();
    $oneHash = {
        param (
            $File
        )
        Get-FileHash $File.FullName -Algorithm SHA1
    }
    $files = Get-ChildItem -R  $Dir
    $handles = 
    foreach ($file in $files) {
        if ( $file.Length -ne 1 -and $file.Name -notmatch "^sha1sum_at_.*\.txt$") { 
            $powershell = [powershell]::Create().AddScript( $oneHash ).AddArgument($file);
            $powershell.RunspacePool = $Pool;
            $powershell.BeginInvoke();
            $threads += $powershell;
        } 
    }
    $cnt = $handles.Count;
    $running = $handles.Count;
    do {
        $i = 0
        $done = $true
        foreach ($handle in $handles) {
            if ($null -ne $handle) {
                if ($handle.IsCompleted) {
                    $ansers += $threads[$i].EndInvoke($handle)
                    $threads[$i].Dispose()
                    $handles[$i] = $null
                    $running--;
                }
                else {
                    $done = $false
                }
            }
            $i++
        }
        if (-not $done) { 
            $dpercent = (1 - ($running / $cnt))
            $percent = [int]($dpercent * 100);
            $pos = $Host.UI.RawUI.CursorPosition
            $pos.x = 0;
            # $pos.y = $pos.y;
            if ($Host.UI.RawUI.WindowSize.Height - $pos.y -le 2) {
                $pos.y -= 2;
            }
            $fillWide = $Host.UI.RawUI.WindowSize.Width - 2;
            $fillStr = "[$($fill * ([int]($dpercent * $fillWide)))$($empty*([int]((1-$dpercent)*$fillWide)))]";
            Write-Host "$cnt Mission ,$running is Waiting , $percent % Complite"
            Write-Host "$fillStr"
            $Host.UI.RawUI.CursorPosition = $pos;
            Start-Sleep -Milliseconds $updateSpeed 
        }
    } until ($done)
    $ansers = $ansers | Sort-Object -Property Path
    foreach ($rec in $ansers) {
        $ans = "$($rec.Path) $($rec.Hash)"
        Write-Output $ans |
        Out-File -FilePath $OutFile -Encoding utf8 -Append;
        Write-Host $ans
    }
}
finally {
    
}