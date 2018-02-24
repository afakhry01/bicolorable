#Bourne shell unit test for jolly
#
#Adopted from shell by Josh Lee
#
echo ""
echo "***Run all jolly unit tests***"
echo "-----------------------------"
echo ""
echo ""

#----------------------------------------
#Create new jolly executable
#----------------------------------------
g++ ../jollyLFM.cpp -o jolly

#---------------------------------
# Set flag that not all tests pass
#---------------------------------
fileOutMismatchFlg=false

#------------------------
# Process all input files
#------------------------
for i in 1 2
do
	#----------------------------------
	#Remove previous input/output files
	#----------------------------------
	rm -f In*
	rm -f testOut
	rm -f GoldOut*
	
	#----------------------------------
	#Copy input and gold file from TestFiles/ 
	#----------------------------------
	cp ../biColorableTestFiles/jjIn$i.txt In$i
	cp ../biColorableTestFiles/jjGoldOut$i.txt GoldOut$i

	#----------------------------------------
	#Display input test case
	#----------------------------------------
	echo "Input In$i:"
	echo "-----------"
	cat In$i
	echo " "
	echo " "	
	#----------------------------------------
	#Process input test case
	#----------------------------------------
	./jolly <In$i >testOut
	echo "Output from In$i:"
	echo "-----------------"
	cat testOut
	echo " "
	#-----------------------------------
	#Check if test gives prior result
	#-----------------------------------
	cmpRslt=`cmp testOut GoldOut$i`
	if [ -n "$cmpRslt" ]; then
		fileOutMismatchFlg=true	
		echo "FAILS TO MATCH GoldOut$1"
		cat GoldOut$1
		echo ""
	else
		echo "matches GoldOut$i"
	fi
	echo ""
	echo ""
done	
echo "-------------------------------"
echo "***Ran all jolly unit  tests****"
echo ""