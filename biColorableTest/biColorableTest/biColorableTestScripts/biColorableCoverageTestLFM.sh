#Executable Bourne again  shell coverage test for jolly
#
#Adapted from shell by Josh Lee
#
echo ""
echo "**Starting jolly coverage test**"
echo "********************************"
echo ""

#---------------------------------------------
#Remove old coverage output
#Remove old source files
#Copy source file - must be in same directory
#----------------------------------------------
rm -f JollyJumpersLeeJoshO.gcda
rm -f JollyJumpersLeeJoshO.gcno
rm -f JollyJumpersLeeJoshO.cpp.gcov
rm -f JollyJumpersLeeJoshOcov
rm -f testOut
rm -f coverageOut

#---------------------------------------------
#Remove old source files
#Copy source file - must be in same directory
#----------------------------------------------
rm -f jollyLFM.cpp
cp ../jollyLFM.cpp jolly.cpp

#----------------------------------------------------------------
#Compile with flags to embed code to capture coverage information
#----------------------------------------------------------------
g++ -fprofile-arcs -ftest-coverage jolly.cpp -o jollyCoverage

#------------------------------------------
#Run all test files for cumulative coverage
#------------------------------------------
for i in 1 2
do
	cp ../biColorableTestFiles/jjIn$i.txt In$i
	echo "Input file In$i:"
	echo "-----------------"
	cat  In$i
	echo ""
	echo ""
	./jollyCoverage <In$i >testOut
	gcov jolly.cpp > coverageOut
done

#---------------------------------------
#Any statements that were not executed
#are marked in JollyJumpersLeeJoshO.cpp.gcov with ‘####’
#----------------------------------------
echo "START JollyJumpersLeeJoshO.cpp STATEMENTS NOT EXECUTED:"
cat jolly.cpp.gcov | grep '####'
echo "END JollyJumpersLeeJoshO.cpp STATEMENTS NOT EXECUTED."
echo ""

echo "********************************************"
echo "**Ending JollyJumpersLeeJoshO coverage test*"
echo ""
