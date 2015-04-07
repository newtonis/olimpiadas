var
	ent, sal : text;
	aux : string;
	a : array[1..3] of ansistring;
	i, can, l : byte;
	d : array[1..50] of byte;
	t : array[1..50] of smallint;
	p : array[1..50] of longint;
	y, costo, aux1, mej1, mej2, gan : longint;

begin
	assign(ent, 'ganancia.in');
	reset(ent);	
	readln(ent, aux);
	val(aux, can, i);
	for i:= 1 to can do
		begin
			a[1]:= '';
			a[2]:= '';
			a[3]:= '';
			readln(ent, aux);
			l:= 1;
			for y:= 1 to length(aux) do
				begin
						if (aux[y]<>' ') then a[l]:= a[l]+aux[y]
						else l:= l+1;
				end;
			val(a[1], d[i], l);
			val(a[2], t[i], l);
			t[i]:= t[i]*(-1);
			costo:= costo+t[i];
			val(a[3], p[i], l);
		end;
	close(ent);
	writeln(costo);
	for l:= 1 to can do
	begin	
	for y:= 1 to can do
		begin
			if (d[y]>0) then
				begin
					aux1:= ((costo-t[y])*d[y])+p[y];
					if (aux1>mej1) then
						begin
							
							mej1:= aux1;
							mej2:= y;
						end;
				end;
		end;
	gan:= gan+mej1;
	costo:= costo-t[mej2];
	d[mej2]:= 0;
	t[mej2]:= 0;
	p[mej2]:= 0;
	mej1:= 0;
	mej2:= 0;
	
	end;
	assign(sal, 'ganancia.out');
	rewrite(sal);
	writeln(sal, gan);
	close(sal);
end.

