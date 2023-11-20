while true
do
echo "1.insert \n 2.display \n 3.search \n 4.modify \n 5.delete \n 6.exit \n"
echo "enter choice="
read ch
case $ch in

1) echo "enter eid="
read eid
echo "enter ename="
read ename
echo "enter eno.="
read eno
echo "enter ecity="
read ecity

echo "$eid \t $ename \t $eno \t $ecity \n">>emp.txt
;;
2)echo "displaying table :\n"
cat emp.txt
;;
3)echo "enter name you want to search="
read ename
grep $ename emp.txt
;;
4)echo "enter name you want to modify="
read ename
echo "enter new name="
read name

sed -i s/$ename/$name/g emp.txt
;;
5)echo "enter name you want to delete="
read ename
grep -v $ename emp.txt>>temp.txt
rm emp.txt
mv temp.txt emp.txt
;;
6)exit
;;


*)
esac

done




