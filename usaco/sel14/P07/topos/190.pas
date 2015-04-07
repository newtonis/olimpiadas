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




procedure der(p : longint);
var
	ii, h, c, par : longint;
begin
	h:= 1;
	if (aux[p]='(') then 
		begin
			sa:=sa+'(';
			par:= par+1;
		end
	else if (aux[p]<>'(')
	else if ((aux[p+1]=')')and(p<length(aux))) then 
		begin
			sa:= sa+'(';
			par:= par+1;
			agregar(p+1);
		end
	else if ((aux[p+1]=')')and(p=length(aux))) then 
		begin
			sa:= sa+aux[1];
			par:= par-1;
		end
		
		begin
			c:= 
			while(h>0) do
				begin
						
				end;
		end;

end;


for i:= 1 to length(aux) do
		begin
			if (aux[i]='Z') then
				begin
					if (aux[i+1]=')') then
							begin
								can:= i;
								while (can>0) do
									begin
											can:= can-1;
											if(aux[can]=')') then p:=p+1
											else if (aux[can]='(')and(p<>0) then p:= p-1
											else if (aux[can]='(')and(p=0) then 
												begin
													for y:= can to i-1 do
														begin
															sa:= sa+aux[y];
															can:= 0;
														end
													sa:= '('+sa+')';
												end;
											
									end;
							end
					else if (aux[i+1]='(') then
							begin
								can:= i;
								while (can>0) do
									begin
											can:= can+1;
											if(aux[can]='(') then p:=p+1
											else if (aux[can]=')')and(p<>0) then p:= p-1
											else if (aux[can]=')')and(p=0) then 
												begin
													for y:= can to i-1 do
														begin
															sa:= aux[y]+;
															can:= 0;
														end
													sa:= '('+sa+')';
												end;
											
									end;
							end
							
					
				end
		end;
	sa:='Z: ';
procedure agregar(p : longint);
var

begin
	if ((aux[p+1]=')')and(p<length(aux))) then agregar(p+1)
	else if ((aux[p+1]=')')and(p=length(aux))) then
		begin
			o:= true;
			sa:= aux[1]+sa;
		end
	else if (((aux[p+1]<>')')or(aux[p+1]<>'('))and(p<length(aux)and(o=false)) then
end;
