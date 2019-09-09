;;;; Exercise 1.3

;;; Define a procedure that takes three numbers as arguments and returns the sum of the squares of the two larger numbers.


(define (sum-of-squares-of-two-larger-numbers x y z)
  (define (sum-of-squares x y)
    (+ (square x) (square y)))
  (define (smaller x y z)
    (and (< x y) (< x z)))
  (define (smallest x y z)
    (cond ((smaller x y z) x)
          ((smaller z y x) z)
          (else y)))
  (cond ((= (smallest x y z) x) (sum-of-squares y z))
        ((= (smallest x y z) y) (sum-of-squares x z))
        (else (sum-of-squares x y))))

(sum-of-squares-of-two-larger-numbers 3 4 5) ; 41