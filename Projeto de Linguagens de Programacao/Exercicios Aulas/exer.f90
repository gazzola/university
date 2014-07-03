program EXER
	implicit none
 	integer :: i,j,k

	print*, 'J:'
 	read *,j

 	k = (j+13)/27;

 	do while (k<=10)
	  	k = k+1;
		i = 3*k - 1;
	end do

	print*,k
	print*,i

	stop
end