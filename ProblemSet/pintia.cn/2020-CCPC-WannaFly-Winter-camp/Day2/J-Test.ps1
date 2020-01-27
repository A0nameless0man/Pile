$dif = ""
$i = 0
$F = ".\J.$($args[0]).in"
Write-Output "Generiting Num"
$num = py .\J-Gen-Num.py
Write-Output $F
try {
    while (-not $dif) {
        $i = $i + 1
        # Clear-Host
        Write-Output "$args Pying$i"
        $testCase = py .\J-gen.py
        # Clear-Host
        Write-Output "$args Other$i"
        $a = Write-Output "$testCase $num" | .\J-Other.exe
        # Clear-Host
        Write-Output "$args Quick$i"
        $b = Write-Output "$testCase $num" | .\J.exe
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