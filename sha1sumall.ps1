$date = Get-Date;
$Dir = "./";
if ($args.Count -ne 0) {
    $Dir = $args[0];
}
$OutFile = $Dir + "sha1sum_at_$date.txt".Replace('/', '-').Replace(' ', '-').Replace(':', '-');
Write-Output $OutFile;
try {
    Get-ChildItem -R  $Dir |
    ForEach-Object {
        if ( $_.Length -ne 1 -and $_.Name -notmatch "^sha1sum_at_.*\.txt$") { 
            $pos = $Host.UI.RawUI.CursorPosition
            Write-Host -NoNewline $($_.FullName)
            $Host.UI.RawUI.CursorPosition = $pos
            $ans = "$($_.FullName) $($(Get-FileHash $_.FullName -Algorithm SHA1).HASH.ToLower())"
            Write-Output $ans |
            Out-File -FilePath $OutFile -Encoding utf8 -Append;
            Write-Host $ans
        } }
}
finally {
    
}