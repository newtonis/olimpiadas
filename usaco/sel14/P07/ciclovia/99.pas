type
	es = record
		ver1, ver2, hor1, hor2 : word;
	end;
var
	ent, sal : text;
	esq : array[1..1000000] of es;
	front : array[1..1000000] of word;
	aux, aux2, aux3 : string;
	i, y, v, h, a, e1, e2, b1, b2 : word;

procedure buscar(ant : word);
var
	m : word;
begin
		if (a=1) then
			begin
				front[2]:= esq[(4*b1)+e1].ver1;
				esq[(4*b1)+e1].ver2:= esq[front[2]].ver2+esq[(4*b1)+e1].ver2;
				esq[(4*b1)+e1].hor2:= esq[front[2]].hor2+esq[(4*b1)+e1].hor2;
			end
		else
			begin
				for i:= 1 to a do
					if (((m<>0)and(esq[front[i]].ver2<esq[m].ver2)and(esq[m].ver1=ant)) or ((m<>0)and(esq[front[i]].hor2<esq[m].hor2)and(esq[m].hor1=ant))) then
						begin
							m:= i;
						end
					else if (m=0) then
						m:= i;
			end;
			
end;

begin
	assign(ent, 'ciclovia.out');
	reset(ent);
	readln(ent, aux);
	a:= 1;
	for i:= 1 to length(aux) do
		begin
			if (aux[i]<>' ') then
				begin
					if (a=1) then aux2:= aux2+aux[i]
					else aux3:= aux3+aux[i];
				end
			else inc(a);
		end;
	val(aux2, v, a);
	val(aux3, h, a);
	for i:= 1 to v do
		begin
			readln(ent, aux);
			a:= 1;
			for y:= 1 to length(aux) do
				begin
					if (aux[y]<>' ') then
						begin
							if (a=1) then aux2:= aux2+aux[y]
						else aux3:= aux3+aux[y];
						end
						else inc(a);
				end;
			val(aux2, e1, a);
			val(aux3, e2, a);
			if (e1=0) then 
				for y:= 1 to h do
				begin
					esq[i].ver1:= i*y;
					esq[i].ver2:= e2;	
				end;
		end;
		
	for i:= 1 to h do
		begin
			readln(ent, aux);
			a:= 1;
			for y:= 1 to length(aux) do
				begin
					if (aux[y]<>' ') then
						begin
							if (a=1) then aux2:= aux2+aux[y]
						else aux3:= aux3+aux[y];
						end
						else inc(a);
				end;
			val(aux2, e1, a);
			val(aux3, e2, a);
			if (e1=0) then 
				for y:= 1 to v do
				begin
					esq[i].hor1:= y+((i-1)*4);
					esq[i].hor2:= e2;	
				end;
		end;
	readln(ent, aux);
	for i:= 1 to length(aux) do
		begin
			a:= 1;
			if (aux[i]<>' ') then
				begin
					if (a=1) then aux2:= aux2+aux[i]
					else aux3:= aux3+aux[i];
				end
			else inc(a);
		end;
	val(aux2, e1, a);
	val(aux3, b1, a);
	
	readln(ent, aux);	
	a:= 1;
	for i:= 1 to length(aux) do
		begin
			if (aux[i]<>' ') then
				begin
					if (a=1) then aux2:= aux2+aux[i]
					else aux3:= aux3+aux[i];
				end
			else inc(a);
		end;
	val(aux2, e2, a);
	val(aux3, b2, a);
	close(ent);
	
	front[1]:= (4*b1)+e1;
	a:= 1;
	
	assign(sal, 'ciclovia.out');
	reset(sal);
	
	close(sal);
end.
