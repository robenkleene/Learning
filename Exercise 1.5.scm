;;;; Exercise 1.5

;;; (define (p) (p))

(define (test x y)
  (if (= x 0)
      0
      y))

;;; (test 0 (p))

;;; Applicative-order evaluation will result in an infinite loop, because in applicative-order evaluation arguments are evaluated before they are applied. So p calls itself before the body of the `test` procedure is entered.

;; Normal-order evaluation will not result in an infinite loop, because in normal-order evaluation arguments are not evaluated until they are needed. So Ben's call to the `test`.