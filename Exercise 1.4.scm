;;;; Exercise 1.4

;;;; Observe that our model of evaluation allows for combinations whose operators are compound expressions. Use this observation to describe the behavior of the following procedure:

(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

(a-plus-abs-b 5 5) ;; 10
(a-plus-abs-b 5 -5) ;; 10
(a-plus-abs-b -5 -5) ;; 0

;;; The if statement returns the `+` operator if `b` is greater than zero otherwise the `-` operator. The returned operator is then used to evaluate the arguements: `a` and `b`. In this way, the absolute value of `b` is added to the value of `a`.
