;;;; Exercise 1.1

(define a 3)				; 3
(define b (+ a 1))			; void
(+ a b (* a b))				; 19
(= a b)					; #f
(if (and (> b a) (< b (* a b)))
    b
    a)					; 4
(cond ((= a 4) 6)
      ((= b 4) (+ 6 7 a))
      (else 25))			; 16
(+ 2 (if (> b a) b a))			; 6
(* (cond ((> a b) a)
         ((< a b) b)
         (else -1))
   (+ a 1))				; 16

;;;; Exercise 1.2

(/ (+ (+ 5 4)
      (- 2
         (- 3
            (+ 6
               (/ 4 5)))))
   (* 3
      (* (- 6 2)
         (- 2 7))))			; -37/150

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

;;;; Exercise 1.4

;;;; Observe that our model of evaluation allows for combinations whose operators are compound expressions. Use this observation to describe the behavior of the following procedure:

(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

(a-plus-abs-b 5 5) ;; 10
(a-plus-abs-b 5 -5) ;; 10
(a-plus-abs-b -5 -5) ;; 0

;;; The if statement returns the `+` operator if `b` is greater than zero otherwise the `-` operator. The returned operator is then used to evaluate the arguements: `a` and `b`. In this way, the absolute value of `b` is added to the value of `a`.

;;;; Exercise 1.5

;;; (define (p) (p))

(define (test x y)
  (if (= x 0)
      0
      y))

;;; (test 0 (p))

;;; Applicative-order evaluation will result in an infinite loop, because in applicative-order evaluation arguments are evaluated before they are applied. So p calls itself before the body of the `test` procedure is entered.

;; Normal-order evaluation will not result in an infinite loop, because in normal-order evaluation arguments are not evaluated until they are needed. So Ben's call to the `test`.

;;;; Exercise 1.6

;;; An infinite loop because all three of the arguments to `new-if` will be evaluated before the body of `new-if` even executes. Since the third argument to `new-if` calls the `sqrt-iter` procedure itself again, this will result an infinite recursive calls to `sqrt-ter`.

(define (sqrt x)
  (define (sqrt-iter guess x)
    (if (good-enough? guess x)
        guess
        (sqrt-iter (improve guess x)
                   x)))
  (define (improve guess x)
    (average guess (/ x guess)))
  (define (average x y)
    (/ (+ x y) 2))
  (define (good-enough? guess x)
    (< (abs (- (square guess) x)) 0.001))
  (sqrt-iter 1.0 x))

(sqrt 9)				; 3.00009155413138
(sqrt (+ 100 37))			; 11.704699917758145
(sqrt (+ (sqrt 2) (sqrt 3)))		; 1.7739279023207892
(square (sqrt 1000))			; 1000.000369924366

;;;; Exercise 1.7

;;; Good

(sqrt 2)              ; 1.4142156862745097 ; Actual 1.4142156862745097
(sqrt .44)            ; .6633286959747728  ; Actual 0.6633249581
(sqrt 20000000010000) ; 4472135.956117613  ; Actual 4472135.9561176134

;;; Bad

(sqrt .00004)               ; .03167509508023218 ; Actual 0.0063245553
(sqrt .0001)                ; .03230844833048122 ; Actual 0.01
(sqrt .0023)                ; .05261937032580024 ; Actual 0.0479583152
(sqrt 200000000100009999)   ; Infinite Loop

;;; For very small numbers, the algorithm is inaccurate if the radicand is not significantly greater than the tolerence.

;;; For very large numbers, the arithmetic operation comparing the calculated guess to the radicand will never pass if the impercision of the computer's arithmetic operation is greater than our tolerence. This will result in an infinite loop.


(define (sqrt x)
  (define (sqrt-iter guess last-guess x)
    (define (good-enough? guess last-guess)
      (< (abs (- guess
                 last-guess))
         (* 0.001 guess)))
    (define (improve guess x)
      (define (average x y)
        (/ (+ x y)
           2))
      (average guess
               (/ x guess)))
    (if (good-enough? guess
                      last-guess)
        guess
        (sqrt-iter (improve guess x)
                   guess
                   x)))
  (sqrt-iter 1.0 2.0 x))

;;; Slower but more elegant solution from the internet

(define (sqrt x)
  (define (sqrt-iter guess x)
    (define (improve guess x)
      (define (average x y)
        (/ (+ x y)
           2))
      (average guess
               (/ x guess)))
    (define (good-enough? guess x)
      (< (abs (- guess
                 (improve guess
                          x)))
         (* 0.001 guess)))
    (if (good-enough? guess
                      x)
        guess
        (sqrt-iter (improve guess x)
                   x)))
  (sqrt-iter 1.0  x))



;;; Good

(sqrt 2)              ; 1.4142135623746899 ; Actual 1.4142156862745097
(sqrt .44)            ; .6633249580816116  ; Actual 0.6633249581
(sqrt 20000000010000) ; 4472135.95611844  ; Actual 4472135.9561176134

;;; Bad

(sqrt .00004)            ; 6.324555320407774e-3 ; Actual 0.0063245553
(sqrt .0001)             ; 1.0000000025490743e-2 ; Actual 0.01
(sqrt .0023)             ; 4.7958315235167776e-2 ; Actual 0.0479583152
(sqrt 200000000100009999)      ; 447213599.6832925 ; 4.4721359561×10^8

;;; Yes, the improved procedure works better for very small and very large numbers.

;;;; Exercise 1.8

(define (cbrt x)
  (define (cbrt-iter guess x)
    (define (improve guess x)
      (/ (+ (/ x
               (square guess))
            (* 2 guess))
         3))
    (define (good-enough? guess x)
      (< (abs (- guess
                 (improve guess
                          x)))
         (* 0.001 guess)))
    (if (good-enough? guess
                      x)
        guess
        (cbrt-iter (improve guess x)
                   x)))
  (cbrt-iter 1.0  x))

(cbrt 27) ; 3.001274406506175



