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



