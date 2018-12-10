echo "contest name"
read contest
mkdir $contest
cd $contest
for i in 1 2 3 4 5
do
	touch $i".cpp"
    cat /home/kunal_goyal/Desktop/codeforces-master/main.cc > $i".cpp"
done 
