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

;; Exercise 1.4

;; Observe that our model of evaluation allows for combinations whose operators are compound expressions. Use this observation to describe the behavior of the following procedure:

(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

(a-plus-abs-b 5 5) ;; 10
(a-plus-abs-b 5 -5) ;; 10
(a-plus-abs-b -5 -5) ;; 0

;; The if statement returns the `+` operator if `b` is greater than zero otherwise the `-` operator. The returned operator is then used to evaluate the arguements: `a` and `b`. In this way, the absolute value of `b` is added to the value of `a`.

;; Exercise 1.5

;; (define (p) (p))

(define (test x y)
  (if (= x 0)
      0
      y))

;; (test 0 (p))

;; Applicative-order evaluation will result in an infinite loop, because in applicative-order evaluation arguments are evaluated before they are applied. So p calls itself before the body of the `test` procedure is entered.

;; Normal-order evaluation will not result in an infinite loop, because in normal-order evaluation arguments are not evaluated until they are needed. So Ben's call to the `test`.

;; Exercise 1.6

;; An infinite loop because all three of the arguments to `new-if` will be evaluated before the body of `new-if` even executes. Since the third argument to `new-if` calls the `sqrt-iter` procedure itself again, this will result an infinite recursive calls to `sqrt-ter`.
