function [matriz] = MatrizCalor(alfa,m)
    matriz=(1+2*alfa)*eye((m-1),(m-1))
    d=-alfa*eye((m-2),(m-2))
    matriz(1:(m-2),2:(m-1))=matriz(1:(m-2),2:(m-1))+d
    matriz(2:(m-1),1:(m-2))=matriz(2:(m-1),1:(m-2))+d
endfunction
