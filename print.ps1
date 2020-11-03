$content = Get-Content "$($args[0])"
$dir = [system.IO.Path]::GetDirectoryName($args[0])
$name = [system.IO.Path]::GetFileNameWithoutExtension($args[0])
$txtf = "${dir}\${name}.txt"
$txtf
$converted = ""
$linecnt = 1
foreach ($line in $content) {
    $converted += "$linecnt $line`n"
    ++$linecnt
}
Out-File -FilePath $txtf -Encoding utf8 -InputObject $converted
notepad /p $txtf