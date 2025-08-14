# test_ajax
test project

Спочатку я створила репозиторій на GitHub. Далі через GitBash я додала локальний репозиторій (за допомогою команди git init).
Підключила зовнішній репозиторій з командою git remote add origin. Додала файли до локального репозиторію (git add .), створила перший коміт
"Creating first commit" (команда git commit -m "Creating first commit"). 
Далі відправила файли на сервер (git push --set-upstream origin main). Виник конфлікт через те, що на GitHub був вже створений коміт з файлом ReadMe. Тому за допомогою команди git pull origin main --rebase я завантажила файли в локальний репозиторій, а потім додала все на сервер. Через GitHub модифікувала файл sketch_jul31a, створила новий коміт Update sketch_jul31a.ino, і додала його до локального репозиторію за допомогою команди git pull. 

