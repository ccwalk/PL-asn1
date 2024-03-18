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

;;; Question 2

(defun expo (u x list) (let ((N (length list))) (let ((result (* #C(0.0 1.0) (* -2 pi (/ (* u x) N))))) result)))

(defun 2a (list-r) (let ((sum 0) (list-f '())) (dotimes (u (- (length list-r) 1) list-f) (dotimes (x (- (length list-r) 1)) (setq sum (+ sum (* (nth x list-r) (exp (round(realpart(expo u x list-r)))))))) (push sum list-f))))


