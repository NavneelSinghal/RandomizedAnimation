step=2
speed=6

if [ $# -gt 0 ]; then
    step=$1
    let "speed = 3 * $step * $2"
fi

g++ -o simulation simulation.cpp

for ((i=35;i<=60;i=$(($i + $step)))); do
    ./simulation 0.${i} > out
    gnuplot plotscript.gp
    mv out.png $i.png
done

for ((i=35;i<=60;i=$(($i + $step)))); do
    if [ $i -gt 50 ]; then
        cp $i.png 0$((60 - $i)).png
    else
        cp $i.png $((60 - $i)).png
    fi
done

convert -delay $speed -loop 0 *.png animation.gif

rm *.png
rm simulation
rm out
