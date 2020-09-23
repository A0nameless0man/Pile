$dif = ""
$i = 0
$F = ".\1005.$($args[0]).in"
Write-Output "Generiting Num"
# $num = py .\1005.gen.py
Write-Output $F
try {
    while (-not $dif) {
        $i = $i + 1
        # Clear-Host
        Write-Output "$args Pying$i"
        $testCase = py .\1005.gen.py
        # Clear-Host
        Write-Output "$args My$i"
        $a = Write-Output "$testCase" | .\1005.exe
        # Clear-Host
        Write-Output "$args True$i"
        $b = Write-Output "$testCase" | .\1005.syf.exe
        $dif = Compare-Object $a $b
        # Clear-Host
        Write-Output "$args Time$i"
        # Write-Output $a
    }
}
catch {   
}
Write-Output "$testCase" >$F
Write-Output $dif