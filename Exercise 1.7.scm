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