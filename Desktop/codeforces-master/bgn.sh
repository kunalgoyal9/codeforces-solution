echo "contest name"
read contest
mkdir $contest
for i in 1 2 3 4 5
do
	touch $contest"/"$i".cpp"
    cat $(pwd)"/main.cc" > $contest"/"$i".cpp"
done 
