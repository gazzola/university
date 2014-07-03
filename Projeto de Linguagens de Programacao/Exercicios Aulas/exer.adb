with Ada.Integer_Text_IO;
with Ada.Text_Io;
use Ada.Text_Io;
 
procedure Exer is
  i,j,k   : Integer;
begin
  
  Ada.Text_Io.Put ("J: ");
  Ada.Integer_Text_IO.Get (j);
  k := (j+13)/27;

  while k <= 10 loop
   		k := k+1;
		i := 3*k - 1;
  end loop;
 
  Ada.Integer_Text_IO.Put (k);
  Ada.Text_Io.New_Line;
  Ada.Integer_Text_IO.Put (i);

end Exer;