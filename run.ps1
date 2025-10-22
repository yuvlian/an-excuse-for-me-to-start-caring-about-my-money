$Output = "a.exe"
$Sources = @("main.c", "csv.c", "fs.c", "tm.c", "ftable.c")
$Flags = @("-Wall", "-Wextra", "-std=c11", "-O3")

Write-Host "compiling project..."
Write-Host "src: $($Sources -join ', ')"
Write-Host "out: $Output"
Write-Host ""

& gcc @Flags @Sources -o $Output

if ($LASTEXITCODE -eq 0) {
    Write-Host "`n[ok] build succ. running..."
    Write-Host ""
    & ".\$Output"
} else {
    Write-Host "`n[err] build failed."
    exit $LASTEXITCODE
}
