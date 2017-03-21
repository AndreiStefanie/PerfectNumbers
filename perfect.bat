for /L %%i in (1, 1, %1) do (
	start PerfectNumbers\Debug\PerfectNumbers.exe 2 400000 %1 %%i
)