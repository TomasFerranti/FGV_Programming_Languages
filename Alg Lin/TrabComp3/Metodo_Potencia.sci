function [lambda,x,N]=Metodo_Potencia(A,x0,epsilon,M)
    p=find(x0==max(abs(x0)))(1)
    x=x0/x0(p)
    for N=1:M
        y=A*x
        lambda=y(p)
        p=find(y==max(abs(y)))(1)
        if y(p)==0
            disp("A tem autovalor 0, selecione um novo vetor x e recomece.")
            return
        end
        ERR=norm(x-y/y(p),%inf)
        x=y/y(p)
        if ERR<epsilon
            disp("Autovalor e autovetor encontrados!")
            x=x(:,1)
            return
        end
    end
    x=x(:,1)
    disp("O valor máximo de iterações foi alcançado. Não obtivemos sucesso.")
endfunction
