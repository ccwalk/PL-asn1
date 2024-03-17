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
