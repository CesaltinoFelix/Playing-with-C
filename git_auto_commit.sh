#!/bin/bash


COMMIT_SMS="Updating code"


# Verifique se há alterações
if git diff --quiet; then
    echo "Nenhuma alteração para commit."
    exit 0
fi

git add .


git commit -m "$COMMIT_SMS"


git push
