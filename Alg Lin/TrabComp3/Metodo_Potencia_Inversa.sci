function [lambda,x,N] = Metodo_Potencia_Inversa(A,x0,epsilon,M,alfa)
    n=size(A,1)
    if(alfa==%inf)
        alfa=x0'*A*x0/(x0'*x0)
    end
    p=find(x0==max(abs(x0)))(1)
    x=x0/x0(p)
    for N=1:M
        [y, C, P]=Gaussian_Elimination_4(A-alfa*eye(n,n), x)
        if sum(isnan(y)+y==%inf)>0
            disp("q é um autovalor")
            return
        end
        lambda=y(p)
        p=find(x==max(abs(x)))(1)
        ERR=norm(x-(y/y(p)),%inf)
        x=y/y(p)
        if ERR<epsilon
            disp("Autovalor e autovetor encontrados!")
            lambda=(1/lambda)+alfa
            return
        end
    end
    disp("O valor máximo de iterações foi alcançado. Não obtivemos sucesso.")
endfunction
