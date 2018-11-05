Sobre o banco de dados "classicmodels", indique as queries para obter as seguintes informações:

- Quantos registros há na tabela "customers"?

select count(customerNumber) AS QuantidadeDeRegistros from customers

- Na tabela "customers", quantos clientes ("customerName") têm nome iniciado pela letra "M"?

select count(*) as QuantidadeDeNomesIniciadosComM from customers where customerName like 'M%'

- Na tabela "customers", crie uma saída que concatene nomes e sobrenomes em uma única coluna.

select CONCAT(contactFirstName,' ',contactLastName) from customers

- Agora repita a query acima, mas com todas as letras em maiúsculo, e ordene pelo sobrenome.

select UPPER(CONCAT(contactFirstName,' ',contactLastName)) from customers order by contactLastName

- Na tabela "payments", selecione os registros ordenados por volume ("amount") e data de pagamento ("paymentDate")

select * from payments order by amount,paymentDate DESC

- Na tabela "employees", indique quantos nomes de cargos ("jobTitle") únicos existem? 

select count(distinct(jobTitle)) from employees

- Qual destes cargos ("jobTitle") possuem mais funcionários?

select jobTitle,count(*) from employees group by jobTitle