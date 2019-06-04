vagrant up
echo|set /p="(make flash && echo && echo '* Flash successful.*') || (echo && >&2 echo '* ERROR WHILE FLASHING! *')" | vagrant ssh
pause