# Titanic Dataset - Data Card

**Last Updated:** 2025-08-11 07:52:29

## Dataset Overview

- **Rows:** 891
- **Columns:** 20
- **Missing Values:** 0
- **Duplicates:** 109

## Column Information

| Column | Type | Non-Null Count | Description |
|--------|------|----------------|-------------|
| survived | int64 | 891 | Survival status (0=No, 1=Yes) |
| pclass | int64 | 891 | Dataset column |
| sex | object | 891 | Gender of passenger |
| age | float64 | 891 | Age of passenger |
| sibsp | int64 | 891 | Dataset column |
| parch | int64 | 891 | Dataset column |
| fare | float64 | 891 | Ticket fare |
| embarked | object | 891 | Port of embarkation |
| class | category | 891 | Passenger class (1st, 2nd, 3rd) |
| who | object | 891 | Category (man, woman, child) |
| adult_male | bool | 891 | Adult male indicator |
| deck | category | 891 | Deck level |
| embark_town | object | 891 | Embarkation town |
| alive | object | 891 | Survival status (text) |
| alone | bool | 891 | Traveling alone indicator |
| age_imputed_flag | int64 | 891 | Generated flag column |
| embarked_imputed_flag | int64 | 891 | Generated flag column |
| deck_imputed_flag | int64 | 891 | Generated flag column |
| embark_town_imputed_flag | int64 | 891 | Generated flag column |
| fare_outlier_flag | int64 | 891 | Generated flag column |

## Data Quality

### Missing Values (Original Dataset)

- **age:** 177 (19.9%)
- **embarked:** 2 (0.2%)
- **deck:** 688 (77.2%)
- **embark_town:** 2 (0.2%)

### Imputation Flags

The following flag columns were created to track imputed values:

- **age_imputed_flag:** 177 records (19.9%)
- **embarked_imputed_flag:** 2 records (0.2%)
- **deck_imputed_flag:** 688 records (77.2%)
- **embark_town_imputed_flag:** 2 records (0.2%)
- **fare_outlier_flag:** 116 records (13.0%)

### Outlier Treatment

- **fare:** winsorization at 5th and 95th percentiles applied to 116 outliers

## Usage Notes

- This dataset has been cleaned and preprocessed for analysis
- Flag columns indicate where imputation occurred
- All missing values have been addressed
- Outliers in fare have been treated using winsorization
- Suitable for machine learning and statistical analysis
