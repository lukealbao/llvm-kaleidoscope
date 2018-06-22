#!/usr/bin/emacs --script

(require 'cc-mode)

(setq require-final-newline 'visit)
(setq c-default-style "gnu")

(defun indent-files (files)
  (dolist (file files)
    (find-file file)
    (indent-region (point-min) (point-max))
    (untabify (point-min) (point-max))
    (save-buffer)
    (kill-buffer (current-buffer))))

(indent-files command-line-args-left)

;; EOF ;;
