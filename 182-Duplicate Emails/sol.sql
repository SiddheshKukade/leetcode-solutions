# Write your MySQL query statement below

with temp_table as(
    select 
    email, row_number() over (
        partition by email 
        order by id asc
    )
    as r_num
    from person
)
select distinct email from temp_table
where r_num <>1
