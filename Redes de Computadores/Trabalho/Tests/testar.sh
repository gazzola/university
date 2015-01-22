#!/bin/sh

# mac, op
tipo="mac"

# MAC, OpModes
pasta="MAC"

FILENAME="saidas/bateria_"$tipo".out"

if [ $# -ne 1 ]
then
	echo "Deve ser informado o numero de execucoes"
	exit 1
fi

for fl in $pasta/*.out; do
	echo "" > $fl
done


getState()
{
	echo "Execuction: #"$i >> $FILENAME
	echo "Present rate(mW) : " `cat /proc/acpi/battery/BAT0/state | grep "present rate" | awk '{ print $3 }'` >> $FILENAME
	echo "Present Voltage(mV): " `cat /proc/acpi/battery/BAT0/state | grep "present voltage" | awk '{print $3}'` >> $FILENAME
	echo "Remaining capacity(mWh): " `cat /proc/acpi/battery/BAT0/state | grep "remaining" | awk '{print $3}'` >> $FILENAME
	echo " " >> $FILENAME
}



echo "" > $FILENAME
i=0
getState
echo "===============================" >> $FILENAME

for i in $(seq $1)
do
	echo "Execuction: #"$i
	getState
	#./run.sh op OpModes
	./run.sh $tipo $pasta $i
done

echo "===============================" >> $FILENAME
i=0
getState