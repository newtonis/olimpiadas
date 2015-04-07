var
	tab : array[1..1000, 1..1000] of char;
	ent, sal : text;
	aux, ff, cc, mm : string;
	f, c, m, i, a, y, cant : integer;


procedure buscar(l : char; xx, yy : integer);
var
	b : integer;
begin
	if (l='C') then
		begin
		b:= a;
		buscar(aux[a], -2, -1);
	a:= b;
	buscar(aux[a], -2, 1);
	a:= b;
	buscar(aux[a], 2, -1);
	a:= b;
	buscar(aux[a], 2, 1);
	a:= b;
	buscar(aux[a], -1, -2);
	a:= b;
	buscar(aux[a], 1, -2);
	a:= b;
	buscar(aux[a], -1, 2);
	a:= b;
	buscar(aux[a], 1, 2);
	a:= b;
		end
	else	if ((0<i+xx)and(i+xx<f)and(0<y+yy)and(y+yy<c)and(tab[i+xx, y+yy]=l)) then
		begin
			if (a<7) then
				begin
					i:= i+xx;
					y:= y+yy;
					inc(a);
						begin
							b:= a;
							buscar(aux[a], -2, -1);
	a:= b;
	buscar(aux[a], -2, 1);
	a:= b;
	buscar(aux[a], 2, -1);
	a:= b;
	buscar(aux[a], 2, 1);
	a:= b;
	buscar(aux[a], -1, -2);
	a:= b;
	buscar(aux[a], 1, -2);
	a:= b;
	buscar(aux[a], -1, 2);
	a:= b;
	buscar(aux[a], 1, 2);
	a:= b;
						end;
				end
			else cant:= cant+1;
		end;
end;

begin
	assign(ent, 'caballos.in');
	reset(ent);
	readln(aux);
	a:= 1;
	for i:= 1 to length(aux) do
		begin
			if (aux[i]<>' ') then
				begin
					if (a=1) then ff:= ff+aux[i]
					else if (a=2) then cc:= cc+aux[i]
					else mm:= mm+aux[i];
				end
			else inc(a);
		end;
	val(ff, f, a);
	val(cc, c, a);
	val(mm, m, a);
	for i:= 1 to f do
		begin
			readln(aux);
			for y:= 1 to c do tab[i, y]:= aux[y];
		end;
	close(ent);
	
	aux:= 'CABALLO';
	for i:= 1 to f do
		for y:= 1 to c do
			if (tab[i, y]='C') then 
				begin
					a:= 2;
					buscar(aux[2], 0, 0);
				end;
					
	assign(sal, 'caballos.out');
	rewrite(sal);
	if (cant<>0) then writeln(sal, cant mod m)
	else writeln(sal, 0);
//	writeln(sal, '1');
	close(sal);
end.
