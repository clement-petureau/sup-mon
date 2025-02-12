# sup-mon
Documentation Utilisateur

Présentation du Jeu

Supémon est un jeu de combat au tour par tour où vous capturez et entraînez des créatures appelées Supémons.

Installation et Compilation
    
Installez un compilateur C (ex: gcc).
Ouvrez un terminal et accédez au dossier du projet.

Exécutez la commande : make
    
Lancez le jeu : ./supmon

Gameplay
    •    Créer un personnage : Vous devez entrer votre nom au début du jeu.
    •    Combattre : Vous pouvez affronter d’autres dresseurs et utiliser des objets en combat.
    •    Soigner ses Supémons : Allez au Centre Supémon pour restaurer leur santé.
    •    Acheter des objets : La boutique propose des potions et des objets spéciaux.
    •    Sauvegarder la partie : Votre progression peut être enregistrée et rechargée.

    

Documentation Développeur

Structure du Projet
    •    include/ : Contient les fichiers .c
    •    src/ : Contient les fichiers .h
    •    Makefile : Automatisation de la compilation

Explication des fichiers
    •    main.c : Gère le lancement du jeu et la sauvegarde du joueur.
    •    player.c / player.h : Gestion du personnage et de son équipe.
    •    battle.c / battle.h : Mécanique de combat et utilisation des attaques.
    •    supemon.c / supemon.h : Définition des Supémons et de leurs caractéristiques.
    •    center.c / center.h : Fonctionnalité de soins.
    •    shop.c / shop.h : Boutique d’objets.
