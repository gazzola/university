<?php

function multMatrix($matrix1, $matrix2){
	
	$tam = count($matrix1);
	$mat = array(array());

	for($i=0; $i<$tam; $i++)
		for($j=0; $j<$tam; $j++)
			$mat[$i][$j] = 0;

	for($i=0; $i<$tam; $i++)
		for($j=0; $j<$tam; $j++)
			for($k=0; $k<$tam; $k++)
				$mat[$i][$j] += $matrix1[$i][$k]*$matrix2[$k][$j];

	return $mat;
}


$tam = $_SERVER['argv'][1];
$mat1 = array(array());
$mat2 = array(array());

for($i=0; $i<$tam; $i++){
	for($j=0; $j<$tam; $j++){
		$mat1[$i][$j] = ($i+1)+($j+1);
		$mat2[$i][$j] = ($i+1)*($j+1);
	}
}

multMatrix($mat1, $mat2);


?>