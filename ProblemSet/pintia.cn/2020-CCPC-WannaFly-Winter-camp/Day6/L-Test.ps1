$dif = ""
$i = 0
$F = ".\L.$($args[0]).in"
$a = ""
$b = ""
Write-Output $F
try {
    while (-not $dif) {
        $i = $i + 1
        Clear-Host
        Write-Output ` $args Pying$i`
        $testCase = py .\L-gen.py
        Clear-Host
        Write-Output ` $args Other$i`
        $a = Write-Output "$testCase $num" | .\L-HXR.exe
        Clear-Host
        Write-Output ` $args Quick$i`
        $b = Write-Output "$testCase $num" | .\L.exe
        $dif = Compare-Object $a $b
        Clear-Host
        Write-Output ` $args Time$i`
        # Write-Output $a
    }
}
catch {
    Write-Output $testCase >$F
    Write-Output $dif
}
finally {
    
}
Write-Output $testCase >$F
Write-Output $dif