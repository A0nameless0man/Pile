$dif = ""
$i = 0
$F = ".\D.$($args[0]).in"
Write-Output "Generiting Num"
$num = py .\D.gen.py
# $num = 
Write-Output $F
try {
    while (-not $dif) {
        $i = $i + 1
        # Clear-Host
        Write-Output "$args Pying$i"
        $testCase = py .\D.gen.py
        # Clear-Host
        Write-Output "$args Other$i"
        $a = Write-Output "$testCase $num" | .\D.other.exe
        # Clear-Host
        Write-Output "$args Quick$i"
        $b = Write-Output "$testCase $num" | .\D.exe
        $dif = Compare-Object $a $b
        # Clear-Host
        Write-Output "$args Time$i"
        # Write-Output $a
    }
}
catch {   
}
Write-Output "$testCase $num" >$F
Write-Output $dif