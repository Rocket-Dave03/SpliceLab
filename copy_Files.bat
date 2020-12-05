echo %1
echo %2
echo %3

robocopy %1Data %1%2\\%3\Data "/MIR" "/IS" "/IT" "/IM"
EXIT 0