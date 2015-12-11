#TEST 1

#Graphe Vide

echo "test n°1"

diff -wB testsGraphe/out1.dot testsGraphe/exp1.dot

if [ $? -eq 0 ]

        then

		echo "test n°1 PASSED"


	else

		echo "test n°1 FAILED"

fi



#TEST 2

#Un sommet seul

echo "test n°2"


diff -wB testsGraphe/out2.dot testsGraphe/exp2.dot

if [ $? -eq 0 ]

        then

		echo "test n°2 PASSED"


	else

		echo "test n°2 FAILED"

fi



#TEST 3

#2 sommets et 2 arêtes

echo "test n°3"

diff -wB testsGraphe/out3.dot testsGraphe/exp3.dot

if [ $? -eq 0 ]

        then

		echo "test n°3 PASSED"


	else

		echo "test n°3 FAILED"

fi



#TEST 4

#Plusieurs sites toujours isoles

echo "test n°4"

diff -wB testsGraphe/out4.dot testsGraphe/exp4.dot

if [ $? -eq 0 ]

        then

		echo "test n°4 PASSED"


	else

		echo "test n°4 FAILED"

fi



#TEST 5

#Aucun site isole

echo "test n°5"

diff -wB testsGraphe/out5.dot testsGraphe/exp5.dot

if [ $? -eq 0 ]

        then

		echo "test n°5 PASSED"


	else

		echo "test n°5 FAILED"

fi



#TEST 6

#Test Random

echo "test n°6"

diff -wB testsGraphe/out6.dot testsGraphe/exp6.dot

if [ $? -eq 0 ]

        then

		echo "test n°6 PASSED"


	else

		echo "test n°6 FAILED"

fi



#TEST 7

#Test Rajout du .dot

echo "test n°7"

diff -wB testsGraphe/out7.txt.dot testsGraphe/exp7.dot

if [ $? -eq 0 ]

        then

		echo "test n°7 PASSED"


	else

		echo "test n°7 FAILED"

fi


#TEST 8
#Test Troncature des pages de plus de 30 caractères

echo "test n°8"

diff -wB testsGraphe/out8.txt.dot testsGraphe/exp8.dot

if [ $? -eq 0 ]

        then

		echo "test n°8 PASSED"


	else

		echo "test n°8 FAILED"

fi
