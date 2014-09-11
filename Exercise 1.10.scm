;;;; Exercise 1.10

;;; The following procedure computes a mathematical function called Ackermann's function.

(+ 1 2)

(define (A x y)
  ;; (bkpt x y)
  (cond ((= y 0) 0)
        ((= x 0) (* 2 y))
        ((= y 1) 2)
        (else (A (- x 1)
                 (A x (- y 1))))))

;;; What are the values of the following expressions?

(A 1 10) ; 1024 
(A 2 4)  ; 65536
(A 3 3)  ; 65536

;;; Consider the following procedures, where A is the procedure defined above:

(define (f n) (A 0 n))
(define (g n) (A 1 n))
(define (h n) (A 2 n))
(define (k n) (* 5 n n))

;;; Give concise mathematical definitions for the functions computed by the procedures f, g, and h for positive integer values of n. For example, (k n) computes 5n2.

;;; Notes

;;; (A 1 10) is the equivalent of evaluating 2^10 

;;; Parameters for (A 2 4):

;;; (The result is the equivalent to 2^16)

;; 2 4
;; 2 3
;; 2 2
;; 2 1
;; 1 2
;; 1 1
;; 0 2

;; 1 4
;; 1 3
;; 1 2
;; 1 1
;; 0 2
;; 0 4
;; 0 8
;; 1 16
;; 1 15
;; 1 14
;; 1 13
;; 1 12
;; 1 11
;; 1 10
;; 1 9
;; 1 8
;; 1 7
;; 1 6
;; 1 5
;; 1 4
;; 1 3
;; 1 2
;; 1 1
;; 0 2
;; 0 4
;; 0 8
;; 0 16
;; 0 32
;; 0 64
;; 0 128
;; 0 256
;; 0 512
;; 0 1024
;; 0 2048
;; 0 4096
;; 0 8192
;; 0 16384
;; 0 32768


(define (A x y)
  ;; (bkpt x y)
  (cond ((= y 0) 0)
        ((= x 0) (* 2 y))
        ((= y 1) 2)
        (else (A (- x 1)
                 (A x (- y 1))))))
(A 3 3)  ; 65536

(A 3 3)
(A (- 3 1) (A 3 (- 3 1)))
(A 2 (A 3 2))
(A 2 (A (- 3 1) (A 3 (- 2 1))))
(A 2 (A 2 (A 3 1)))
