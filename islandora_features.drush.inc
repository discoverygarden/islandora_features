<?php
/**
 * @file
 * Custom CWRC drush scripts.
 */

/**
 * Implements hook_drush_command().
 */
function islandora_features_drush_command() {

  $items = array();
  $items['islandora_features_enable'] = array(
    'description' => 'This command needs to be called after a feature is enabled',
    'examples' => array(
      'drush -u 1 islandora_features_enable',
    ),
    'bootstrap' => DRUSH_BOOTSTRAP_MAX,
  );

  return $items;
}

/**
 * Islandora_Features enable.
 *
 * Clears the cache and rebuilds the menu.
 */
function drush_islandora_features_enable() {

  // We need to clear all the cache.
  drupal_flush_all_caches();

  // The following functions need to be run because drupal_flush_all_caches()
  // runs rebuilds in the wrong order. The node type cache is rebuilt *after*
  // the menu is rebuilt, meaning that the menu tree is stale in certain
  // circumstances after drupal_flush_all_caches(). We rebuild again.
  menu_rebuild();
  
  drush_print("Islandora feature is enabled completely.");

}
