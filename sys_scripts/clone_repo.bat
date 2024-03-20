@echo off

setlocal

set destination=../libs

for /f %%a in (valid_libs.spv) do (
   git clone https://github.com/%%a.git %destination%
)

endlocal
exit