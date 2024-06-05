var 
    a, b, tmp: integer;
    
procedure swap(var x, y: integer);
    begin
        tmp := x;
        x := y;
        y := tmp;
    end;

begin
    read(a);
    read(b);
    swap(a, b);
    write(a, ' ', b);
end.