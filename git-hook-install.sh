#!/bin/bash
HOOKFILE=.git/hooks/pre-commit

echo "#!/bin/bash" > $HOOKFILE
echo "make -sC 2015/ -j8 && make -sC 2015/ test" >> $HOOKFILE
chmod 0744 $HOOKFILE
