var
	tab : array[1..1000, 1..1000] of char;
	ent, sal : text;
	aux, ff, cc, mm : string;
	f, c, m, i, a, y, cant, n, nn : integer;


procedure buscar(l : char; xx, yy : integer);
var
	b, o, p : integer;
begin
	if ((0<(n+xx))and((n+xx)<=f)and(0<(nn+yy))and((nn+yy)<=c)and(tab[n+xx, nn+yy]=l)) then
		begin
			if (a<7) then
				begin
					n:= n+xx;
					nn:= nn+yy;
					o:= n;
					p:= nn;
					a:= a+1;
						begin
							b:= a;
							buscar(aux[a], -2, -1);
							n:= o;
							nn:= p;
	a:= b;
	buscar(aux[a], -2, 1);
n:= o;
							nn:= p;
	a:= b;
	buscar(aux[a], 2, -1);
n:= o;
							nn:= p;
	a:= b;
	buscar(aux[a], 2, 1);
n:= o;
							nn:= p;
	a:= b;
	buscar(aux[a], -1, -2);
n:= o;
							nn:= p;
	a:= b;
	buscar(aux[a], 1, -2);
n:= o;
							nn:= p;
	a:= b;
	buscar(aux[a], -1, 2);
n:= o;
							nn:= p;
	a:= b;
	buscar(aux[a], 1, 2);
n:= o;
							nn:= p;
	a:= b;
						end;
				end
			else cant:= cant+1;
		end;
end;

begin
	assign(ent, 'caballos.in');
	reset(ent);
	readln(ent, aux);
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
			readln(ent, aux);
			for y:= 1 to c do tab[i, y]:= aux[y];
		end;
	close(ent);
	aux:= 'CABALLO';
	for i:= 1 to 6 do
		begin
		for y:= 1 to c do
			begin
			if (tab[i, y]='C') then 
				begin
					n:= i;
					nn:= y;
					
					a:= 2;
					buscar('A', -2, -1);
					n:= i;
					nn:= y;
					a:= 2;
					buscar('A', -2, 1);
					n:= i;
					nn:= y;
					a:= 2;
					buscar('A', 2, -1);
					n:= i;
					nn:= y;
					a:= 2;
	buscar('A', 2, 1);
	n:= i;
					nn:= y;
	a:= 2;
	buscar('A', -1, -2);
	n:= i;
					nn:= y;
	a:= 2;
	buscar('A', 1, -2);
	n:= i;
					nn:= y;
	a:= 2;
	buscar('A', -1, 2);
	n:= i;
					nn:= y;
	a:= 2;
	buscar('A', 1, 2);
	a:= 2;
				end;
			end;
		end;	

	assign(sal, 'caballos.out');
	rewrite(sal);
	writeln(sal, cant mod m)
	close(sal);
end.
