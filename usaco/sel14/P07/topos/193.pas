var
	ent, sal : text;
	aux, aux1: ansistring;
	i, c, x, p : longint;
	a :array[1..800] of shortstring;
	p1, p2 : char;


begin
	assign(ent, 'topos.in');
	reset(ent);
	readln(ent, aux);
	close(ent);
	c:= 1;
	for i:= 1 to length(aux) do
		begin
			if (aux[i]='Z') then
				begin
					x:= i;
					p:= 1;
					for c:= x+1 to length(aux) do
						begin
							if (aux[c]<>'(')and(aux[c]<>')') then 
								begin
									a[p]:=a[p]+aux[c];
									aux[c]:= '1';
									if (aux[c+1]<>'(')and(aux[c+1]<>')') then 
										begin
											a[p]:=a[p]+aux[c+1];
											aux[c+1]:= '1';
										end;
											
									p:= p+1;
								end;
						end;
					for c:= 1 to x-1 do
						begin
							if (aux[c]<>'(')and(aux[c]<>')') then 
								begin
									a[p]:=a[p]+aux[c];
									aux[c]:= '1';
									if (aux[c+1]<>'(')and(aux[c+1]<>')') then 
										begin
											a[p]:=a[p]+aux[c+1];
											aux[c+1]:= '1';
										end;
											
									p:= p+1;
								end;
						end;
				end;
		end;
	c:= 1;
	for i:= 1 to length(aux) do
		begin
			if (aux[i]<>'(')and(aux[i]<>')')and(aux[i]='1') then 
				begin
					if (length(a[c])=1) then 
						begin
							aux1:= a[c];
							p1:= aux1[1];
							aux[i]:= p1;
							
						end
					else 
						begin
							aux1:= a[c];
							p1:= aux1[1];
							p2:= aux1[2];
							aux[i]:=p1;
							aux[i+1]:=p1;

						end;
				end;
		end;

	for i:= 3 to length(aux) do
		begin
			if (aux[i]='Z') then aux[i]:= aux[1];
		end;
	aux[1]:= ':';			
	aux:= 'Z'+aux;	
	assign(sal, 'topos.out');
	rewrite(sal);
	writeln(sal, aux);
	close(sal);
end.


