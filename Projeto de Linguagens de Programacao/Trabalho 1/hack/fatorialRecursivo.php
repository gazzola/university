<?hh

function fatRec(int $n): int{
	if($n < 2)
		return 1;
	return $n*fatRec($n-1);
}

$n = intval($_SERVER['argv'][1]);
print(fatRec($n)."\n");