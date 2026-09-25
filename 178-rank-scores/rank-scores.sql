# Write your MySQL query statement below
with ranked_score as
(
    select score,
    dense_rank() over (order by score desc) as rnk
    from Scores
)
select  score, rnk as 'rank'
from ranked_score
order by rnk