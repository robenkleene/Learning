;; Exercise 1.1

(define a 3) ;; 3
(define b (+ a 1)) ;; void
(+ a b (* a b)) ;; 19
(= a b) ;; #f
(if (and (> b a) (< b (* a b)))
    b
    a) ;; 4
(cond ((= a 4) 6)
      ((= b 4) (+ 6 7 a))
      (else 25)) ;; 16
(+ 2 (if (> b a) b a)) ;; 6
(* (cond ((> a b) a)
         ((< a b) b)
         (else -1))
   (+ a 1)) ;; 16

;; Exercise 1.2

(/ (+ (+ 5 4)
      (- 2
	 (- 3
	    (+ 6
	       (/ 4 5)))))
   (* 3
      (* (- 6 2)
	 (- 2 7)))) ;; -37/150

;; Exercise 1.3

;; Define a procedure that takes three numbers as arguments and returns the sum of the squares of the two larger numbers.


(define (sum-of-squares-of-two-larger-numbers x y z)
  (define (square x) (* x x))
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

(sum-of-squares-of-two-larger-numbers 3 4 5) ;; 41
