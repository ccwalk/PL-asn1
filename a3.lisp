#|  
 | Callie Walker and Emma Smith
 | Prof. Gentry
 | CS451 Programming Languages
 | 20 March 2024
 |
 | Assignment 3 - (More) Functional Progamming in Lisp
 |
 |#


;;; Question 1
(defun leibniz (n) "Returns a list of n terms of the Leibniz formula sequence" (declare (number n)) (if (and (plusp n) (integerp n)) (let ((lst '())) (push '+ lst) (dotimes (i n lst) (push (* (expt (- 1) (+ i 2)) (/ 4 (+ (* 2 i) 1))) lst)) (reverse lst))))

;;; Question 2a

(defun expo (u x list) (let ((N (length list))) (let ((result (* #C(0.0 1.0) (* -2 pi (/ (* u x) N))))) result)))

(defun 2a (list-r) (let ((sum 0) (list-f '())) (dotimes (u (- (length list-r) 1) list-f) (dotimes (x (- (length list-r) 1)) (setq sum (+ sum (* (nth x list-r) (exp (round(realpart(expo u x list-r)))))))) (push sum list-f))))


;;;Updated 2a 3/19

    (defun 2a (list-r ) (let ((list-c '()) (N (length list-r))) (dotimes (n N list-c) (let ((sum #C(0.0 0.0))) (dotimes (k N) (setq sum (+ sum (* (nth k list-r) (exp (expo k n list-r)))))) (push sum list-c)))))

;;;Test

(defvar list-r '(1 2 3 4))
 (let ((result (2a list-r)))
  (format t "Result: ~a~%" result))
;;; Question 2b

 (defun expoinv (u x list) (let ((N (length list))) (let ((result (* #C(0.0 1.0) (* 2 pi (/ (* u x) N))))) result)))

(defun 2b (list-c) (let ((sum 0) (list-r '())) (dotimes (x (length list-c) list-r) (let ((sum 0)) (dotimes (u (length list-c)) (setq sum (+ sum (* (nth x list-c) (exp (round(realpart(expoinv x u list-c)))))))) (push (/ sum (length list-c)) list-r)) list-r)))


;;;Updated 3/19 2b 

(defun 2b (list-c) (let ((sum 0) (list-r '())) (dotimes (x (length list-c) list-r) (let ((sum (* #C(0.0 0.0)))) (dotimes (u (length list-c)) (setq sum (+ sum (* (nth x list-c) (exp (round(realpart(expo-i x u list-c)))))))) (push (/ sum (length list-c)) list-r)) list-r)))

;;;Test

(defvar list-c '(10 #C(-2.0 2.0 ) #C(-2.0 0.0) #C(-2.0 -2.0))) 
 (let ((result (2b list-c)))                                                                   (format t "Result: ~a~%" result))   
