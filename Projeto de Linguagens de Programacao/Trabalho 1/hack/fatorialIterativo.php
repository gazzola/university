<?hh

function fatIter(int $n): int{
	$x = 1;
	for($i=1; $i<=$n; $i++) 
		$x *= $i;
	return $x;
}

$n = intval($_SERVER['argv'][1]);
print(fatIter($n)."\n");