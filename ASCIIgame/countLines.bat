@ECHO OFF
cd %cd%
PowerShell.exe "(dir -include *.py -recurse | select-string .).Count"
Echo Lines of Code
PAUSE